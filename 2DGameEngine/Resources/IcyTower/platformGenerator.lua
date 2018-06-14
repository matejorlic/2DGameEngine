function Start()

ballTransform = GameObject.Find("ball"):GetComponent("Transform"):ToTransform()

nextY = 0
nextX = 0

debugBox = GameObject.Create()
debugBox:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/platform.png")
debugBox:AddComponent("BoxCollider"):ToBoxCollider():SetSize(100 / 2, 50 / 2)
debugBox:GetComponent("Transform"):ToTransform():SetPosition(0, 0)

math.randomseed(os.time())

end

function PPPTest()
	print(1)
end

function Update()
	if(ballTransform:GetPosition().y + 500 > nextY) then
		debugBox = GameObject.Create()
		debugBox:AddComponent("Sprite"):ToSprite():SetTexture("Resources/IcyTower/platform.png")
		debugBox:AddComponent("BoxCollider"):ToBoxCollider():SetSize(100 / 2, 50 / 2)
		debugBox:GetComponent("Transform"):ToTransform():SetPosition(nextX, nextY)
		nextY = nextY + 100
		if(nextX == 0) then
			if(math.random(0, 1) == 0) then
				nextX = 200;
			else 
				nextX = -200;
			end
		else
			nextX = 0;
		end
	end
end