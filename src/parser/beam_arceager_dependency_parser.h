//
// The MIT License (MIT)
//
// Copyright 2013-2014 The MilkCat Project Developers
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
// beam_arceager_dependency_parser.h --- Created at 2014-10-31
//

#ifndef SRC_PARSER_BEAM_ARCEAGER_DEPENDENCY_PARSER_H_
#define SRC_PARSER_BEAM_ARCEAGER_DEPENDENCY_PARSER_H_

#include <vector>
#include <string>
#include "common/model_impl.h"
#include "parser/dependency_parser.h"

namespace milkcat {

class Status;
class MulticlassPerceptronModel;
class MulticlassPerceptron;
class TermInstance;
class PartOfSpeechTagInstance;
class FeatureSet;
template<class T> class Pool;


class BeamArceagerDependencyParser: public DependencyParser {
 public:
  BeamArceagerDependencyParser(
      MulticlassPerceptronModel *perceptron_model,
      FeatureTemplate *feature);
  ~BeamArceagerDependencyParser();

  static BeamArceagerDependencyParser *New(Model::Impl *model,
                                           Status *status);
  // Overrides DependencyParser::Parse
  void Parse(
      DependencyInstance *dependency_instance,
      const TermInstance *term_instance,
      const PartOfSpeechTagInstance *part_of_speech_tag_instance);

 private:
  enum {
    kBeamSize = 3
  };
  Pool<State> *state_pool_;
  float *agent_;
  State **beam_;
  State **next_beam_;
  int beam_size_;
  int agent_size_;

  // Step to next transtions
  void Step();

  // Start to parse the sentence
  void StartParse(
      const TermInstance *term_instance,
      const PartOfSpeechTagInstance *part_of_speech_tag_instance);

  // Stores the parsing result into dependency_instance
  void StoreResult(DependencyInstance *dependency_instance);
};

}  // namespace milkcat

#endif  // SRC_PARSER_BEAM_ARCEAGER_DEPENDENCY_PARSER_H_