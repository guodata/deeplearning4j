/*-
 *  * Copyright 2017 Skymind, Inc.
 *  *
 *  *    Licensed under the Apache License, Version 2.0 (the "License");
 *  *    you may not use this file except in compliance with the License.
 *  *    You may obtain a copy of the License at
 *  *
 *  *        http://www.apache.org/licenses/LICENSE-2.0
 *  *
 *  *    Unless required by applicable law or agreed to in writing, software
 *  *    distributed under the License is distributed on an "AS IS" BASIS,
 *  *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  *    See the License for the specific language governing permissions and
 *  *    limitations under the License.
 */

package org.datavec.codec.reader;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.List;
import org.bytedeco.javacv.FFmpegFrameGrabber;
import org.bytedeco.javacv.Frame;
import org.bytedeco.javacv.OpenCVFrameConverter;
import org.datavec.api.conf.Configuration;
import org.datavec.api.writable.Writable;
import org.datavec.api.util.ndarray.RecordConverter;
import org.datavec.image.loader.NativeImageLoader;

/**
 * An implementation of the CodecRecordReader that uses JavaCV and FFmpeg.
 *
 * @author saudet
 */
public class NativeCodecRecordReader extends BaseCodecRecordReader {

    private OpenCVFrameConverter.ToMat converter;
    private NativeImageLoader imageLoader;

    @Override
    public void setConf(Configuration conf) {
        super.setConf(conf);
        converter = new OpenCVFrameConverter.ToMat();
        imageLoader = new NativeImageLoader(rows, cols);
    }

    @Override
    protected List<List<Writable>> loadData(File file, InputStream inputStream) throws IOException {
        List<List<Writable>> record = new ArrayList<>();

        try (FFmpegFrameGrabber fg =
                        inputStream != null ? new FFmpegFrameGrabber(inputStream) : new FFmpegFrameGrabber(file)) {
            if (numFrames >= 1) {
                fg.start();
                if (startFrame != 0)
                    fg.setFrameNumber(startFrame);

                for (int i = startFrame; i < startFrame + numFrames; i++) {
                    Frame grab = fg.grabImage();
                    record.add(RecordConverter.toRecord(imageLoader.asRowVector(converter.convert(grab))));
                }
            } else {
                if (framesPerSecond < 1)
                    throw new IllegalStateException("No frames or frame time intervals specified");
                else {
                    fg.start();

                    for (double i = 0; i < videoLength; i += framesPerSecond) {
                        fg.setTimestamp(Math.round(i * 1000000L));
                        Frame grab = fg.grabImage();
                        record.add(RecordConverter.toRecord(imageLoader.asRowVector(converter.convert(grab))));
                    }
                }
            }
        }

        return record;
    }

}
