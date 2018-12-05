// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GRAPH_ND4J_GRAPH_H_
#define FLATBUFFERS_GENERATED_GRAPH_ND4J_GRAPH_H_

#include "flatbuffers/flatbuffers.h"

#include "array_generated.h"
#include "config_generated.h"
#include "node_generated.h"
#include "properties_generated.h"
#include "request_generated.h"
#include "result_generated.h"
#include "utils_generated.h"
#include "variable_generated.h"

namespace nd4j {
namespace graph {

struct FlatGraph;

struct FlatDropRequest;

struct FlatResponse;

struct FlatGraph FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4,
    VT_VARIABLES = 6,
    VT_NODES = 8,
    VT_OUTPUTS = 10,
    VT_CONFIGURATION = 12,
    VT_PLACEHOLDERS = 14
  };
  int64_t id() const {
    return GetField<int64_t>(VT_ID, 0);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FlatVariable>> *variables() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FlatVariable>> *>(VT_VARIABLES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<FlatNode>> *nodes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<FlatNode>> *>(VT_NODES);
  }
  const flatbuffers::Vector<flatbuffers::Offset<IntPair>> *outputs() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<IntPair>> *>(VT_OUTPUTS);
  }
  const FlatConfiguration *configuration() const {
    return GetPointer<const FlatConfiguration *>(VT_CONFIGURATION);
  }
  const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *placeholders() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>> *>(VT_PLACEHOLDERS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_ID) &&
           VerifyOffset(verifier, VT_VARIABLES) &&
           verifier.Verify(variables()) &&
           verifier.VerifyVectorOfTables(variables()) &&
           VerifyOffset(verifier, VT_NODES) &&
           verifier.Verify(nodes()) &&
           verifier.VerifyVectorOfTables(nodes()) &&
           VerifyOffset(verifier, VT_OUTPUTS) &&
           verifier.Verify(outputs()) &&
           verifier.VerifyVectorOfTables(outputs()) &&
           VerifyOffset(verifier, VT_CONFIGURATION) &&
           verifier.VerifyTable(configuration()) &&
           VerifyOffset(verifier, VT_PLACEHOLDERS) &&
           verifier.Verify(placeholders()) &&
           verifier.VerifyVectorOfStrings(placeholders()) &&
           verifier.EndTable();
  }
};

struct FlatGraphBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(int64_t id) {
    fbb_.AddElement<int64_t>(FlatGraph::VT_ID, id, 0);
  }
  void add_variables(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FlatVariable>>> variables) {
    fbb_.AddOffset(FlatGraph::VT_VARIABLES, variables);
  }
  void add_nodes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FlatNode>>> nodes) {
    fbb_.AddOffset(FlatGraph::VT_NODES, nodes);
  }
  void add_outputs(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<IntPair>>> outputs) {
    fbb_.AddOffset(FlatGraph::VT_OUTPUTS, outputs);
  }
  void add_configuration(flatbuffers::Offset<FlatConfiguration> configuration) {
    fbb_.AddOffset(FlatGraph::VT_CONFIGURATION, configuration);
  }
  void add_placeholders(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> placeholders) {
    fbb_.AddOffset(FlatGraph::VT_PLACEHOLDERS, placeholders);
  }
  explicit FlatGraphBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlatGraphBuilder &operator=(const FlatGraphBuilder &);
  flatbuffers::Offset<FlatGraph> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlatGraph>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlatGraph> CreateFlatGraph(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t id = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FlatVariable>>> variables = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<FlatNode>>> nodes = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<IntPair>>> outputs = 0,
    flatbuffers::Offset<FlatConfiguration> configuration = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<flatbuffers::String>>> placeholders = 0) {
  FlatGraphBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_placeholders(placeholders);
  builder_.add_configuration(configuration);
  builder_.add_outputs(outputs);
  builder_.add_nodes(nodes);
  builder_.add_variables(variables);
  return builder_.Finish();
}

inline flatbuffers::Offset<FlatGraph> CreateFlatGraphDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t id = 0,
    const std::vector<flatbuffers::Offset<FlatVariable>> *variables = nullptr,
    const std::vector<flatbuffers::Offset<FlatNode>> *nodes = nullptr,
    const std::vector<flatbuffers::Offset<IntPair>> *outputs = nullptr,
    flatbuffers::Offset<FlatConfiguration> configuration = 0,
    const std::vector<flatbuffers::Offset<flatbuffers::String>> *placeholders = nullptr) {
  return nd4j::graph::CreateFlatGraph(
      _fbb,
      id,
      variables ? _fbb.CreateVector<flatbuffers::Offset<FlatVariable>>(*variables) : 0,
      nodes ? _fbb.CreateVector<flatbuffers::Offset<FlatNode>>(*nodes) : 0,
      outputs ? _fbb.CreateVector<flatbuffers::Offset<IntPair>>(*outputs) : 0,
      configuration,
      placeholders ? _fbb.CreateVector<flatbuffers::Offset<flatbuffers::String>>(*placeholders) : 0);
}

struct FlatDropRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ID = 4
  };
  int64_t id() const {
    return GetField<int64_t>(VT_ID, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_ID) &&
           verifier.EndTable();
  }
};

struct FlatDropRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(int64_t id) {
    fbb_.AddElement<int64_t>(FlatDropRequest::VT_ID, id, 0);
  }
  explicit FlatDropRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlatDropRequestBuilder &operator=(const FlatDropRequestBuilder &);
  flatbuffers::Offset<FlatDropRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlatDropRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlatDropRequest> CreateFlatDropRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t id = 0) {
  FlatDropRequestBuilder builder_(_fbb);
  builder_.add_id(id);
  return builder_.Finish();
}

struct FlatResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_STATUS = 4
  };
  int32_t status() const {
    return GetField<int32_t>(VT_STATUS, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_STATUS) &&
           verifier.EndTable();
  }
};

struct FlatResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_status(int32_t status) {
    fbb_.AddElement<int32_t>(FlatResponse::VT_STATUS, status, 0);
  }
  explicit FlatResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  FlatResponseBuilder &operator=(const FlatResponseBuilder &);
  flatbuffers::Offset<FlatResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<FlatResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<FlatResponse> CreateFlatResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    int32_t status = 0) {
  FlatResponseBuilder builder_(_fbb);
  builder_.add_status(status);
  return builder_.Finish();
}

inline const nd4j::graph::FlatGraph *GetFlatGraph(const void *buf) {
  return flatbuffers::GetRoot<nd4j::graph::FlatGraph>(buf);
}

inline const nd4j::graph::FlatGraph *GetSizePrefixedFlatGraph(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<nd4j::graph::FlatGraph>(buf);
}

inline bool VerifyFlatGraphBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<nd4j::graph::FlatGraph>(nullptr);
}

inline bool VerifySizePrefixedFlatGraphBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<nd4j::graph::FlatGraph>(nullptr);
}

inline void FinishFlatGraphBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<nd4j::graph::FlatGraph> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedFlatGraphBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<nd4j::graph::FlatGraph> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace graph
}  // namespace nd4j

#endif  // FLATBUFFERS_GENERATED_GRAPH_ND4J_GRAPH_H_
