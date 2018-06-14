
function Init()

ball = GameObject.Create()
ball.name = "ball"
ball:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/blueBall.png")
ball:AddComponent("SphereCollider"):ToSphereCollider():SetSize(40 / 2)
ball:AddComponent("Rigidbody"):ToRigidbody():SetMass(10)
ball:GetComponent("Transform"):ToTransform():SetPosition(0, 40 / 2)
ball:AddComponent("Script"):ToScript():Init("Resources/IcyTower/ball.lua")

water = GameObject.new()
water:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/water.png")
water:AddComponent("Script"):ToScript():Init("Resources/IcyTower/water.lua")
water:GetComponent("Transform"):ToTransform():SetPosition(0, -450)

platformGenerator = GameObject.new()
platformGenerator:AddComponent("Script"):ToScript():Init("Resources/IcyTower/platformGenerator.lua")

--platformGenerator:GetComponent("Resources/IcyTower/platformGenerator.lua"):ToLuaScript().ball = ball
--platformGenerator:GetComponent("Resources/IcyTower/platformGenerator.lua"):ToLuaScript().PPPTest()

camera = GameObject.Create()
camera.name = "camera"
camera:AddComponent("Camera")
camera:AddComponent("Script"):ToScript():Init("Resources/IcyTower/camera.lua")
end