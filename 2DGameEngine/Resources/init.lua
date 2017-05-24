
function Init()

ball = GameObject.new()
ball:AddComponent("Sprite"):ToSprite():SetTexture("Resources/blueBall.png")
ball:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball:GetComponent("Transform"):ToTransform():SetPosition(40 / 2 + 100, 40 / 2 + 500)

debuxBox = GameObject.new()
debuxBox:AddComponent("Sprite")
debuxBox:AddComponent("BoxCollider"):ToBoxCollider():SetSize(100 / 2, 100 / 2)
debuxBox:GetComponent("Transform"):ToTransform():SetPosition(100 / 2 + 80, 100 / 2 + 100)
debuxBox:GetComponent("Transform"):ToTransform():SetRotation(60)
debuxBox:AddComponent("Script"):ToScript():Init("Resources/debugBox.lua")
end