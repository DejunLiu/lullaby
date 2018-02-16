/*
Copyright 2017 Google Inc. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS-IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef LULLABY_EVENTS_AUDIO_EVENTS_H_
#define LULLABY_EVENTS_AUDIO_EVENTS_H_

#include <string>

#include "lullaby/util/entity.h"
#include "lullaby/util/typeid.h"

namespace lull {

struct AudioLoadedEvent {
  template <typename Archive>
  void Serialize(Archive archive) {}
};

struct DisableAudioEnvironmentEvent {
  template <typename Archive>
  void Serialize(Archive archive) {}
};

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::AudioLoadedEvent);
LULLABY_SETUP_TYPEID(lull::DisableAudioEnvironmentEvent);

#endif  // LULLABY_EVENTS_AUDIO_EVENTS_H_
