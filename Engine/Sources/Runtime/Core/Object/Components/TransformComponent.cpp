#include "Runtime/Core/Object/Components/TransformComponent.h"

using namespace scarlett;

TransformComponent::TransformComponent() :
	mPosition(0.0f, 0.0f, 0.0f),
	mRotation(0.0f, 0.0f, 0.0f, 1.0f),
	mScale(1.0f, 1.0f, 1.0f),
	mWorldMatrixDirty(true),
	mWorldMatrixInverseDirty(true)
{}

void scarlett::TransformComponent::SetRotation(Quaternion rotation)
{
	Normalize(rotation);
	mRotation = rotation;
	mWorldMatrixDirty = true; 
	mWorldMatrixInverseDirty = true;
}

Matrix4x4f scarlett::TransformComponent::GetWorldMatrix()
{
	if (mWorldMatrixDirty) {
		Matrix4x4f translation, scaling, rotate;
		auto position = GetPosition();
		auto scale = GetScale();
		auto rotation = GetRotation();
		BuildMatrixTranslation(translation, position.x, position.y, position.z);
		BuildMatrixScale(scaling, scale.x, scale.y, scale.z);

		MatrixRotationQuaternion(rotate, rotation);

		mWorldMatrix = translation * rotate * scaling; // make sure translation matrix go first.
		mWorldMatrixDirty = false;
	}
	return mWorldMatrix;
}

Matrix4x4f scarlett::TransformComponent::GetWorldMatrixInverse()
{
	if (mWorldMatrixInverseDirty)
	{
		Matrix4x4f translation, scaling, rotate, ratateInverse;
		auto position = GetPosition();
		auto scale = GetScale();
		auto rotation = GetRotation();
		BuildMatrixTranslation(translation, -position.x, -position.y, -position.z);
		BuildMatrixScale(scaling, 1 / scale.x, 1 / scale.y, 1 / scale.z);
		MatrixRotationQuaternion(rotate, rotation);
		Transpose(ratateInverse, rotate);

		mWorldMatrixInverse = scaling * ratateInverse * translation ; // make sure translation matrix go first.
	}
	
	return mWorldMatrixInverse;
}

Vector3f scarlett::TransformComponent::GlobalVectorToLocalVector(Vector3f globalVector)
{
	Matrix4x4f world2local = GetWorldMatrixInverse();
	Vector3f localVector = TransformVector(world2local, globalVector);
	return localVector;
}

Vector3f scarlett::TransformComponent::LocalPointToGlobalPoint(Vector3f localPoint)
{
	Matrix4x4f local2world = GetWorldMatrix();
	Vector3f globalPoint = TransformPoint(local2world, localPoint);
	return globalPoint;
}

Matrix3x3f scarlett::TransformComponent::GetRatationMatrixGlobal2Local33()
{
	Matrix4x4f world2local = GetWorldMatrixInverse();
	Matrix3x3f ret;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ret[i][j] = world2local[i][j];
		}
	}
	return ret;
}

int TransformComponent::Initialize() noexcept
{
	return 0;
}


void TransformComponent::Finalize() noexcept {
}
