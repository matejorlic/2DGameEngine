
function Start()
	ballTransform = GameObject.Find("ball"):GetComponent("Transform"):ToTransform()
	transform = gameObject:GetComponent("Transform"):ToTransform()
end

function Update()
	position = transform:GetPosition()
	if(position.y < ballTransform:GetPosition().y - 450) then 
		transform:SetPosition(position.x, position.y + 2)
	elseif(position.y < ballTransform:GetPosition().y - 350) then 
		transform:SetPosition(position.x, position.y + 1)
	elseif(position.y < ballTransform:GetPosition().y - 300) then 
		transform:SetPosition(position.x, position.y + 0.5)
	else
		os.exit()
	end
end