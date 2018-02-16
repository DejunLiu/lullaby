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

#ifndef LULLABY_SYSTEMS_RENDER_NEXT_SHADER_FACTORY_H_
#define LULLABY_SYSTEMS_RENDER_NEXT_SHADER_FACTORY_H_

#include "lullaby/systems/render/next/shader.h"
#include "lullaby/util/registry.h"
#include "lullaby/util/resource_manager.h"
#include "lullaby/util/span.h"
#include "lullaby/generated/shader_def_generated.h"

namespace lull {

// Creates and manages Shader objects.
//
// Shaders will be automatically released along with the last external
// reference unless they are explicitly cached.
class ShaderFactory {
 public:
  explicit ShaderFactory(Registry* registry);
  ShaderFactory(const ShaderFactory&) = delete;
  ShaderFactory& operator=(const ShaderFactory&) = delete;

  // Loads the shader with the given |filename|.
  ShaderPtr LoadShader(const std::string& filename);

  // Loads the shader from a ShaderDef.
  ShaderPtr LoadShaderFromDef(const ShaderDefT& shader_def);

  // Returns the shader in the cache associated with |key|, else nullptr.
  ShaderPtr GetCachedShader(HashValue key) const;

  // Attempts to add |shader| to the cache using |key|.
  void CacheShader(HashValue key, const ShaderPtr& shader);

  // Releases the cached shader associated with |key|.
  void ReleaseShaderFromCache(HashValue key);

 private:
  ShaderPtr LoadImpl(const std::string& filename);
  ShaderPtr CompileAndLink(const char* vs_source, const char* fs_source);
  ShaderHnd CompileShader(const char* source, ShaderStageType stage);
  ProgramHnd LinkProgram(ShaderHnd vs, ShaderHnd fs,
                         Span<ShaderVertexAttributeDefT> attributes = {});

  Registry* registry_;
  ResourceManager<Shader> shaders_;
};

}  // namespace lull

LULLABY_SETUP_TYPEID(lull::ShaderFactory);

#endif  // LULLABY_SYSTEMS_RENDER_NEXT_SHADER_FACTORY_H_
