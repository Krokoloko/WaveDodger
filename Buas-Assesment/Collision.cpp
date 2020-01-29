#include "Collision.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Collision::Collision() {

}

Collision::Collision(sf::Vector2f* aPosition)
{
	collision = sf::VertexArray(sf::Quads,4);
	collision[0].position = sf::Vector2f(-5,5);
	collision[1].position = sf::Vector2f(5, 5);
	collision[2].position = sf::Vector2f(5, -5);
	collision[3].position = sf::Vector2f(-5, -5);
	_colliding = false;
}

Collision::Collision(Object *aTransform , sf::VertexArray aCollision)
{
	_transform = aTransform;
	collision = aCollision;
}

bool Collision::_isColliding(sf::VertexArray collider) {
	//std::cout << "Self: " << _transform->Position().x << ", " << _transform->Position().y << "\n";
	for (int i = 0; i < collider.getVertexCount()-2; i++) {
		/*std::cout << i << " : ( " << collider[i].position.x << ", " << collider[i].position.y << " )\n";
		std::cout << i + 1 << " : ( " << collider[i + 1].position.x << ", " << collider[i + 1].position.y << " )\n";
		std::cout << i + 2 << " : ( " << collider[i + 2].position.x << ", " << collider[i + 2].position.y << " )\n";*/
		
		if (_isInArea(_transform->Position(), collider[i].position, 
			collider[i+1].position, collider[i+2].position)) {

			return true;

		}
	}
	return false;
}

float Collision::_areaTriangle(sf::Vector2f point1,sf::Vector2f point2,sf::Vector2f point3) {
	float area = abs((point1.x*(point2.y - point3.y)) +
		(point2.x*(point3.y - point1.y)) +
		(point3.x*(point1.y - point2.y)));

	//std::cout << "   :" << area << "\n";

	if (area == 0) {
		return 0;
	}
	else return area / 2;
}

bool Collision::_isInArea(sf::Vector2f point,sf::Vector2f areaPoint1, sf::Vector2f areaPoint2, sf::Vector2f areaPoint3) {
	
	float area = _areaTriangle(areaPoint1, areaPoint2, areaPoint3);
	float area1 = _areaTriangle(point,areaPoint1,areaPoint2);
	float area2 = _areaTriangle(point,areaPoint1,areaPoint3);
	float area3 = _areaTriangle(point,areaPoint3,areaPoint2);
	
	return (area1 + area2 + area3 == area);
}

bool Collision::OnHitStartWith(sf::VertexArray collider) {
	if (_isColliding(collider)) {
		if (!_colliding) {
			_colliding = true;
			return true;
		}
		else return false;
	}
	else return false;
}

bool Collision::OnHitWith(sf::VertexArray collider) {
	if (_isColliding(collider)) {
		return true;
	}
	else return false;
}

bool Collision::OnHitReleaseWith(sf::VertexArray collider) {
	if (!OnHitWith(collider)) {
		_colliding = false;
		return true;
	}
	else return false;
}

Collision::~Collision()
{
}
