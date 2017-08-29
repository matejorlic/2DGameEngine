
function Init()

ball = GameObject.new()
ball:AddComponent("Sprite"):ToSprite():SetTexture("Resources/Test/blueBall.png")
ball:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball:GetComponent("Transform"):ToTransform():SetPosition(40 / 2 + 100, 40 / 2 + 500)

debugBox = GameObject.new()
debugBox:AddComponent("Sprite")
debugBox:AddComponent("BoxCollider"):ToBoxCollider():SetSize(100 / 2, 100 / 2)
debugBox:GetComponent("Transform"):ToTransform():SetPosition(100 / 2 + 80, 100 / 2 + 100)
debugBox:GetComponent("Transform"):ToTransform():SetRotation(60)
debugBox:AddComponent("Script"):ToScript():Init("Resources/Test/debugBox.lua")
debugBox:AddComponent("Camera")
debugBox:AddComponent("Rigidbody"):ToRigidbody():SetMass(100)
debugBox:GetComponent("Rigidbody"):ToRigidbody():SetGravityScale(0)

ball2 = GameObject.new()
ball2:AddComponent("Sprite"):ToSprite():SetTexture("Resources/Test/blueBall.png")
ball2:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball2:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball2:GetComponent("Rigidbody"):ToRigidbody():SetGravityScale(0)
ball2:GetComponent("Transform"):ToTransform():SetPosition(40 / 2 + 200, 40 / 2 + 200)

ball3 = GameObject.new()
ball3:AddComponent("Sprite"):ToSprite():SetTexture("Resources/Test/blueBall.png")
ball3:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball3:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball3:GetComponent("Rigidbody"):ToRigidbody():SetGravityScale(0)
ball3:GetComponent("Transform"):ToTransform():SetPosition(40 / 2 + 100, 40 / 2 + 100)


--camera = GameObject.new()
--camera:AddComponent("Camera")
--camera:GetComponent("Transform"):ToTransform():SetPosition(400, 300)
end