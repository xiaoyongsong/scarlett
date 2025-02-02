add_subdirectory(Sources/Programs)

set(SourcesPath ${PROJECT_SOURCE_DIR}/Engine/Sources)
set(ExternalPath ${PROJECT_SOURCE_DIR}/Engine/External)

IF(${WIN32})
	set(PlatformOnlySources 
	${SourcesPath}/Runtime/Core/Application/WindowsApplication.cpp

	${SourcesPath}/Runtime/RHI/D11/GraphicsMgrD11.cpp
	${SourcesPath}/Runtime/RHI/D11/VertexBufferD11.cpp
	${SourcesPath}/Runtime/RHI/D11/ShaderD11.cpp
	${SourcesPath}/Runtime/RHI/D11/MeshD11.cpp
	${SourcesPath}/Runtime/RHI/D11/IndexBufferD11.cpp
	${SourcesPath}/Runtime/RHI/D11/MaterialD11.cpp
	${SourcesPath}/Runtime/RHI/D11/TextureD11.cpp
	${SourcesPath}/Runtime/RHI/D11/SamplerStateD11.cpp
	${SourcesPath}/Runtime/RHI/D11/DepthStencilStateD11.cpp
	${SourcesPath}/Runtime/RHI/D11/DDSTextureLoader.cpp
	${SourcesPath}/Runtime/RHI/D11/BlendStateD11.cpp

	${ExternalPath}/Glad/src/glad.c
	${ExternalPath}/Glad/src/glad_wgl.c

	)
ELSEIF(${UNIX})
	IF(${APPLE})
	ELSE(${APPLE})
    ENDIF(${APPLE})
ENDIF(${WIN32})


add_library(Scarlett 
${SourcesPath}/Runtime/Core/Memory/Allocator.cpp
${SourcesPath}/Runtime/Core/Memory/MemoryManager.cpp
${SourcesPath}/Runtime/Core/Application/Application.cpp
${SourcesPath}/Runtime/Core/Application/GlobalConfig.cpp
${SourcesPath}/Runtime/Core/Application/AssetFinder.cpp

${SourcesPath}/Runtime/Core/Object/World.cpp
${SourcesPath}/Runtime/Core/Object/Entity.cpp

${SourcesPath}/Runtime/Core/Object/Components/TransformComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/MeshRenderComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/CameraComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/SkeletonComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/TerrainComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/LightComponent.cpp
${SourcesPath}/Runtime/Core/Object/Components/RigidBodyComponent.cpp

${SourcesPath}/Runtime/Core/Object/System/MeshRenderSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/CameraSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/RenderDebugSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/AnimationSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/TerrainSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/LightSystem.cpp
${SourcesPath}/Runtime/Core/Object/System/PhysicsSystem.cpp

${SourcesPath}/Runtime/Core/Time/TimeMgr.cpp
${SourcesPath}/Runtime/Core/Input/InputMgr.cpp
${SourcesPath}/Runtime/Core/Font/FontMgr.cpp

${SourcesPath}/Runtime/Core/Physics/BoardPhase.cpp
${SourcesPath}/Runtime/Core/Physics/NarrowPhase.cpp
${SourcesPath}/Runtime/Core/Physics/Collider.cpp
${SourcesPath}/Runtime/Core/Physics/Contact.cpp
${SourcesPath}/Runtime/Core/Physics/RigidBody.cpp
${SourcesPath}/Runtime/Core/Physics/IntegratePhase.cpp
${SourcesPath}/Runtime/Core/Physics/ResolutionPhase.cpp
${SourcesPath}/Runtime/Core/Physics/Inertia.cpp
${SourcesPath}/Runtime/Core/Physics/AABB.cpp
${SourcesPath}/Runtime/Core/Physics/Jacobian.cpp

${SourcesPath}/Runtime/RHI/opengl/GraphicsMgrGL.cpp
${SourcesPath}/Runtime/RHI/opengl/MeshGL.cpp
${SourcesPath}/Runtime/RHI/opengl/VertexBufferGL.cpp
${SourcesPath}/Runtime/RHI/opengl/IndexBufferGL.cpp
${SourcesPath}/Runtime/RHI/opengl/ShaderGL.cpp
${SourcesPath}/Runtime/RHI/opengl/MaterialGL.cpp
${SourcesPath}/Runtime/RHI/opengl/TextureGL.cpp
${SourcesPath}/Runtime/RHI/opengl/SamplerStateGL.cpp

${SourcesPath}/Runtime/Core/UI/AutoReleasePool.cpp
${SourcesPath}/Runtime/Core/UI/Director.cpp
${SourcesPath}/Runtime/Core/UI/Dispatcher.cpp
${SourcesPath}/Runtime/Core/UI/Event.cpp
${SourcesPath}/Runtime/Core/UI/Listener.cpp
${SourcesPath}/Runtime/Core/UI/Node.cpp
${SourcesPath}/Runtime/Core/UI/Ref.cpp
${SourcesPath}/Runtime/Core/UI/Renderer.cpp
${SourcesPath}/Runtime/Core/UI/Sprite.cpp
${SourcesPath}/Runtime/Core/UI/FontNode.cpp

${SourcesPath}/Runtime/Core/Debug/DebugWindow.cpp

${SourcesPath}/Runtime/Core/ScriptEngine/ScriptEngine.cpp

${PlatformOnlySources}

${SourcesPath}/Runtime/Utils/ImageParser.cpp

# lua script engine
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lapi.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lcode.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lctype.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ldebug.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ldo.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ldump.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lfunc.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lgc.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/llex.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lmem.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lobject.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lopcodes.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lparser.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lstate.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lstring.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ltable.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ltm.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lundump.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lvm.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lauxlib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lbaselib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lcorolib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ldblib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/liolib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lmathlib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/loadlib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/loslib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lstrlib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/ltablib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lutf8lib.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/linit.c
${SourcesPath}/Runtime/Core/ScriptEngine/lua-5.4.2/src/lzio.c

)

IF(${WIN32})
	target_link_libraries(Scarlett user32 d3d11 d3dcompiler dxgi opengl32 dxguid.lib)
	target_link_libraries(Scarlett ${ASSIMP_LIBRARY} ${IRRXML_LIBRARY} ${ZLIB_LIBRARY} ${FREETYPE2_LIBRARY})
ELSEIF(${UNIX})
	IF(${APPLE})
	ELSE(${APPLE})
    ENDIF(${APPLE})
ENDIF(${WIN32})
