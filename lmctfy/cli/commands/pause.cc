// Copyright 2014 Google Inc. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "lmctfy/cli/commands/pause.h"

#include <memory>
#include <string>
using ::std::string;
#include <vector>

#include "lmctfy/cli/command.h"
#include "lmctfy/cli/commands/util.h"
#include "include/lmctfy.h"
#include "util/errors.h"
#include "util/task/status.h"

using ::std::unique_ptr;
using ::std::vector;
using ::util::Status;

namespace containers {
namespace lmctfy {
namespace cli {

// Command to pause a container.
Status PauseContainer(const vector<string> &argv,
                      const ContainerApi *lmctfy,
                      vector<OutputMap> *output) {
  const string container_name = argv[1];

  // Ensure the container exists.
  unique_ptr<Container> container(
      RETURN_IF_ERROR(lmctfy->Get(container_name)));

  return container->Pause();
}

void RegisterPauseCommand() {
  RegisterRootCommand(
      CMD("pause",
          "Pause a container and all of its subcontainers.",
          "<container name>",
          CMD_TYPE_SETTER,
          1,
          1,
          &PauseContainer));
}

}  // namespace cli
}  // namespace lmctfy
}  // namespace containers
