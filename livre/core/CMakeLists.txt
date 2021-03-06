# Copyright (c) 2011-2015, EPFL/Blue Brain Project
#                          Ahmet Bilgili <ahmet.bilgili@epfl.ch>
#                          Stefan.Eilemann@epfl.ch
#
# This file is part of Livre <https://github.com/BlueBrain/Livre>
#

list(APPEND CPPCHECK_EXTRA_ARGS
  --suppress=*:${CMAKE_CURRENT_BINARY_DIR}/*_generated.h)

include(zerobufGenerateCxx)
zerobuf_generate_cxx(ZEROBUF_GENERATED
  ${PROJECT_BINARY_DIR}/include/livre/core/configuration  configuration/rendererParameters.fbs)

set(LIVRECORE_PUBLIC_HEADERS
  data/LODNode.h
  data/Histogram.h
  data/NodeId.h
  data/MemoryUnit.h
  data/DataSourcePlugin.h
  data/VolumeInformation.h
  render/Renderer.h
  render/RendererPlugin.h
  render/RenderPipeline.h
  render/RenderPipelinePlugin.h
  render/GLContext.h
  render/GLSLShaders.h
  mathTypes.h
  types.h
)

set(LIVRECORE_HEADERS
  ${ZEROBUF_GENERATED_HEADERS}
  cache/Cache.h
  cache/CacheObject.h
  cache/CacheStatistics.h
  configuration/Configuration.h
  configuration/Parameters.h
  configuration/RendererParameters.h
  data/DataSource.h
  data/SignalledVariable.h
  events/EventHandler.h
  events/EventHandlerFactory.h
  events/EventInfo.h
  events/EventMapper.h
  render/ClipPlanes.cpp
  render/FrameInfo.h
  render/Frustum.h
  render/SelectVisibles.h
  render/TexturePool.h
  settings/ApplicationSettings.h
  settings/CameraSettings.h
  settings/FrameSettings.h
  settings/RenderSettings.h
  settings/VolumeSettings.h
  util/FrameUtils.h
  visitor/DFSTraversal.h
  visitor/NodeVisitor.h
  visitor/DataSourceVisitor.h
  visitor/DFSTraversal.h
  visitor/VisitState.h)

set(LIVRECORE_SOURCES
  ${ZEROBUF_GENERATED_SOURCES}
  cache/CacheObject.cpp
  cache/CacheStatistics.cpp
  configuration/Configuration.cpp
  configuration/Parameters.cpp
  configuration/RendererParameters.cpp
  data/LODNode.cpp
  data/Histogram.cpp
  data/MemoryUnit.cpp
  data/NodeId.cpp
  data/DataSource.cpp
  data/DataSourcePlugin.cpp
  data/VolumeInformation.cpp
  events/EventMapper.cpp
  render/ClipPlanes.cpp
  render/FrameInfo.cpp
  render/Frustum.cpp
  render/GLContext.cpp
  render/GLSLShaders.cpp
  render/Renderer.cpp
  render/RenderPipeline.cpp
  render/SelectVisibles.cpp
  render/TexturePool.cpp
  settings/ApplicationSettings.cpp
  settings/CameraSettings.cpp
  settings/FrameSettings.cpp
  settings/RenderSettings.cpp
  settings/VolumeSettings.cpp
  util/FrameUtils.cpp
  visitor/DataSourceVisitor.cpp
  visitor/DFSTraversal.cpp
  visitor/VisitState.cpp)

set(LIVRECORE_LINK_LIBRARIES
  PUBLIC ${Boost_LIBRARIES} Collage Lexis Lunchbox Tuyau vmmlib ZeroBuf ${GLEW_LIBRARIES})

set(LIVRECORE_INCLUDE_NAME livre/core)
set(LIVRECORE_NAMESPACE livrecore)
common_library(LivreCore)
