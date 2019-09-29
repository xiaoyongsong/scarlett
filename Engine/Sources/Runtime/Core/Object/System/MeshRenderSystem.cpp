#include "MeshRenderSystem.h"
#include "Runtime/Core/Object/World.h"
#include "Runtime/Core/Application/Application.h"
#include "Runtime/Core/Object/System/MeshRenderSystem.h"


scarlett::MeshRenderSystem::MeshRenderSystem(World * world) :
	mWorld(world)
{
}

int scarlett::MeshRenderSystem::Initialize() noexcept
{
	mGraphicsManager = mWorld->mApp->mGraphicsManager;
	return 0;
}

void scarlett::MeshRenderSystem::Finalize() noexcept
{
	mMeshes.clear();
}

void scarlett::MeshRenderSystem::Tick() noexcept
{
}

void scarlett::MeshRenderSystem::AddComponent(MeshRenderComponent * comp)
{
	mComponents.insert(comp);
}

void scarlett::MeshRenderSystem::DeleteComponent(MeshRenderComponent * comp)
{
	mComponents.erase(comp);
}


void scarlett::MeshRenderSystem::Render()
{
	if (!IsActive())
		return;

	auto camera = mWorld->GetCameraSystem()->GetMainCamera()->GetComponent<CameraComponent>();
	auto view = camera->GetViewMatrix().transpose();
	auto projection = camera->GetPerspectiveMatrix().transpose();

	for (auto comp : mComponents) {
		if (comp->IsVisible()) {

			auto transform = comp->GetMaster()->GetComponent<TransformComponent>();
			for (auto mid : comp->mMeshIdxes) {
				auto mesh = mMeshes[mid];
				if (mesh) {
					mesh->Render(transform->GetWorldMatrix().transpose(), view, projection);
				}
			}
		}
	}
}

void scarlett::MeshRenderSystem::LoadMesh(aiMesh * mesh, const aiScene* world)
{
	auto _mesh = mGraphicsManager->CreateRenderMesh(mesh, world);
	mMeshes.push_back(_mesh);
}
