
function Start()
	transform = gameObject:GetComponent("Transform"):ToTransform()
	position = transform:GetPosition()
	positionDelta = Vector2.new()
	positionDelta.x = 4
	positionDelta.y = 10
end

function Update()
	position = transform:GetPosition()
	
	if(Input.GetKey("Up")) then
		position.y = position.y + positionDelta.y
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("Left")) then
		position.x = position.x - positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("Right")) then
		position.x = position.x + positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
end