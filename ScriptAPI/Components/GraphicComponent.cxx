#include "GraphicComponent.hxx"
#include "components/GraphicsComponent.h"
#include "../EngineInterface.hxx"

namespace ScriptAPI {
	GraphicComponent::GraphicComponent(TDS::EntityID ID) : entityID(ID), transform(TransformComponent(ID)) 
	{
		gameObject = EngineInterface::GetGameObject(ID);
	}
	
	float GraphicComponent::getColourAlpha() 
	{
		if (!TDS::GetGraphicsComponent(entityID))
		{
			// throw error instead (not sure how)
			System::Console::WriteLine("hello");
			return 0.f;
		}
		return TDS::GetGraphicsComponent(entityID)->GetColor().w;
	}

	void GraphicComponent::SetColourAlpha(float value) 
	{
		float r = Color.X;
		float g = Color.Y;
		float b = Color.Z;
		Color = Vector4(r, g, b, value);
	}

	void GraphicComponent::SetModelName(System::String^ name)
	{
		
		TDS::GetGraphicsComponent(entityID)->SetModelName(toStdString(name));
	}

	TDS::EntityID GraphicComponent::GetEntityID() 
	{
		return entityID;
	}

	void GraphicComponent::SetEntityID(TDS::EntityID ID) 
	{
		entityID = ID;
		transform = TransformComponent(ID);
		gameObject = EngineInterface::GetGameObject(ID);
	}

	void GraphicComponent::SetEnabled(bool enabled)
	{
		TDS::setComponentIsEnable("Graphics Component", GetEntityID(), enabled);
	}
	bool GraphicComponent::GetEnabled()
	{
		return TDS::getComponentIsEnable("Graphics Component", GetEntityID());
	}

	Vector4 GraphicComponent::Color::get() 
	{
		if (!TDS::GetGraphicsComponent(entityID))
		{
			// throw error instead (not sure how)
			return Vector4();
		}
		TDS::Vec4 temp = TDS::GetGraphicsComponent(entityID)->GetColor();
		return Vector4(temp.x, temp.y, temp.z,temp.w);
	}

	void GraphicComponent::Color::set(Vector4 value) 
	{
		if (!TDS::GetGraphicsComponent(entityID))
		{
			// throw error instead (not sure how)
			return;
		}
		TDS::GetGraphicsComponent(entityID)->SetColor(value.X, value.Y, value.Z, value.W);
	}

	void GraphicComponent::SetView2D(bool status)
	{
		
		TDS::GetGraphicsComponent(entityID)->SetView2D(status);
	}
	
}