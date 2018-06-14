
function Start()
	transform = gameObject:GetComponent("Transform"):ToTransform()
	rigidbody = gameObject:GetComponent("Rigidbody"):ToRigidbody()
	position = transform:GetPosition()
	positionDelta = Vector2.new()
	positionDelta.x = 4
	positionDelta.y = 10
end

function Update()
	if(Input.GetKeyDown("Up")) then
		velocity = rigidbody:GetVelocity()
		if(velocity.y < 1 and velocity.y > -1) then
			rigidbody:AddForce(0, 300)
		end
	end
	if(Input.GetKey("Left")) then
		position = transform:GetPosition()
		position.x = position.x - positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
	if(Input.GetKey("Right")) then
		position = transform:GetPosition()
		position.x = position.x + positionDelta.x
		transform:SetPosition(position.x, position.y)
	end
end