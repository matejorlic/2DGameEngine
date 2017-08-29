
function Start()
	i = 0
	sprite = gameObject:GetComponent("Sprite"):ToSprite()
	transform = gameObject:GetComponent("Transform"):ToTransform()
	rotation = transform:GetRotation()
	position = transform:GetPosition()
	positionDelta = Vector2.new()
	positionDelta.x = 1
	positionDelta.y = 1
end

function Update()
	i = i + 1
	if i == 1 then
		sprite:SetTexture("Resources/Test/debugBox.png")
	end
	
	rotation = rotation + 1
	transform:SetRotation(rotation)
	
	position = transform:GetPosition()
	
	if(Input.GetKey("W")) then
		position.y = position.y + positionDelta.y
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("A")) then
		position.x = position.x - positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("S")) then
		position.y = position.y - positionDelta.y
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("D")) then
		position.x = position.x + positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
	
	if(Input.GetMouseButton("Left")) then
		position.y = position.y + 5 * positionDelta.y
		transform:SetPosition(position.x, position.y)
	end
	
	if(Input.GetKey("P")) then
		print(Input.GetMousePosition().x .. " " .. Input.GetMousePosition().y)
	end
	
	if(Input.GetMouseButtonDown("Right")) then
		print(Input.GetMousePosition().x .. " " .. Input.GetMousePosition().y)
	end
end