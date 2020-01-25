#include "Collision.h"
#include <SFML/Graphics.hpp>

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

bool Collision::_isColliding(Collision collider) {
	for (int i = 0; i < collider.collision.getVertexCount() - 2; i++) {
		if (_isInArea(_transform->Position(), collider.collision[i].position, 
			collider.collision[i+1].position, collider.collision[i+2].position)) {

			return true;

		}
	}
	return false;
}

float Collision::_areaTriangle(sf::Vector2f point1,sf::Vector2f point2,sf::Vector2f point3) {
	return (point1.x*(point2.y - point3.y) + 
			point2.x*(point3.y - point1.y) + 
			point3.x*(point1.y - point2.y))/2;
}

bool Collision::_isInArea(sf::Vector2f point,sf::Vector2f areaPoint1, sf::Vector2f areaPoint2, sf::Vector2f areaPoint3) {
	
	float area = _areaTriangle(areaPoint1, areaPoint2, areaPoint3);
	float area1 = _areaTriangle(point,areaPoint1,areaPoint2);
	float area2 = _areaTriangle(point,areaPoint1,areaPoint3);
	float area3 = _areaTriangle(point,areaPoint3,areaPoint2);
	
	return (area1 + area2 + area3 == area);
}

bool Collision::OnHitStartWith(Collision collider) {
	if (_isColliding(collider)) {
		if (!_colliding) {
			_colliding = true;
			return true;
		}
		else return false;
	}
	else return false;
}

bool Collision::OnHitWith(Collision collider) {
	if (_isColliding(collider)) {
		return true;
	}
	else return false;
}

bool Collision::OnHitReleaseWith(Collision collider) {
	if (!OnHitWith(collider)) {
		_colliding = false;
		return true;
	}
	else return false;
}

Collision::~Collision()
{
}