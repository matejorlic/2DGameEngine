
function Init()

ball = GameObject.new()
ball:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/blueBall.png")
ball:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball:GetComponent("Transform"):ToTransform():SetPosition(0, 40 / 2)
ball:AddComponent("Script"):ToScript():Init("Resources/ball.lua")

water = GameObject.new()
water:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/water.png")
water:AddComponent("Script"):ToScript():Init("Resources/water.lua")
water:GetComponent("Transform"):ToTransform():SetPosition(0, -300)

platformGenerator = GameObject.new()
platformGenerator:AddComponent("Script"):ToScript():Init("Resources/IcyTower/platformGenerator.lua")

camera = GameObject.new()
camera:AddComponent("Camera")
camera:AddComponent("Script"):ToScript():Init("Resources/IcyTower/camera.lua")
end