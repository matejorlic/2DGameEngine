
function Start()
	ballTransform = GameObject.Find("ball"):GetComponent("Transform"):ToTransform()
	transform = gameObject:GetComponent("Transform"):ToTransform()
end

function Update()

	position = transform:GetPosition()
	if(position.y + 200 < ballTransform:GetPosition().y) then 
		transform:SetPosition(position.x, position.y + 3)
	elseif(position.y + 100 < ballTransform:GetPosition().y) then 
		transform:SetPosition(position.x, position.y + 2)
	elseif(position.y < ballTransform:GetPosition().y) then 
		transform:SetPosition(position.x, position.y + 1)
	end
end