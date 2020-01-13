#include "Collision.h"



Collision::Collision(sf::Vector2f* aPosition)
{
	_position = aPosition;
	collision = sf::VertexArray(sf::Quads,4);
	collision[0].position = sf::Vector2f(-5,5);
	collision[1].position = sf::Vector2f(5, 5);
	collision[2].position = sf::Vector2f(5, -5);
	collision[3].position = sf::Vector2f(-5, -5);
}

Collision::Collision(sf::Vector2f* aPosition, sf::VertexArray aCollision) 
{
	_position = aPosition;
	collision = aCollision;
}

bool Collision::_isColliding(Collision collider) {
	for (int i = 0; i < collider.collision.getVertexCount() - 2; i++) {
		if (_isInArea(*_position, collider.collision[i].position, 
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

bool Collision::OnHitStart(Collision collider) {

}

bool Collision::OnHit(Collision collider) {

}

bool Collision::OnHitRelease(Collision collider) {

}

Collision::~Collision()
{
}
