#pragma once
#include "Runtime/RHI/Mesh.h"
#include <d3d11.h>

namespace scarlett {
	class MeshD11 : public IMesh {
	public:
		MeshD11();
		MeshD11(aiMesh* mesh, const aiScene* world);
		MeshD11(void* data, int count, VertexFormat vf);

		virtual ~MeshD11();

		virtual void Initialize(aiMesh* mesh) noexcept;
		virtual void Initialize(void* data, int count, VertexFormat vf) noexcept;
		virtual void InitializeUI() noexcept;
		virtual void Render(const Matrix4f& worldMatrix, const Matrix4f& viewMatrix, const Matrix4f& projectMatrix) noexcept;
		virtual void RenderWithSkin(const Matrix4f& worldMatrix, const Matrix4f& viewMatrix, const Matrix4f& projectMatrix, const Matrix4f boneMatrix[], const int boneCount) noexcept;

	protected:
		unsigned int*		stride;
		unsigned int*		offset;
		ID3D11Buffer **		vbuffers;
		unsigned int		vbcount;
	};

}