
function Start()
	i = 0
	sprite = gameObject:GetComponent("Sprite"):ToSprite()
	transform = gameObject:GetComponent("Transform"):ToTransform()
	rotation = transform:GetRotation()
	position = transform:GetPosition()
	positionDelta = Vector2.new()
	positionDelta.x = 1
end

function Update()
	i = i + 1
	if i == 30 then
		sprite:SetTexture("Resources/debugBox.png")
	end
	
	rotation = rotation + 1
	transform:SetRotation(rotation)
	
	position.x = position.x + positionDelta.x
	transform:SetPosition(position.x, position.y)
end