#pragma once

class CelestialObject {
    public:
        /** @brief Creates an object with all information
            @param position The position of the object
            @param radius The radius of the object
            @param density The density of the object
            @param velocity The velocity of the object
            @param mass The mass of the object
            @param enabled Whether the object is enabled or disabled
        */
        CelestialObject(Vector2 position, float radius, float density, Vector2 velocity, float mass, bool enabled, PhysicsBody physicsObject) {
            _position = position;
            _radius = radius;
            _density = density;
            _velocity = velocity;
            _mass = mass;
            _enabled = enabled;
            physicsObject->enabled = _enabled;
            physicsObject->velocity = _velocity;
        }

        Vector2 GetPosition() {
            return _position;
        }

        float GetRadius() {
            return _radius;
        }

        float GetDensity() {
            return _density;
        }

        Vector2 GetVelocity() {
            return _velocity;
        }

        float GetMass() {
            return _mass;
        }

        bool IsEnabled() {
            return _enabled;
        }

        void SetVelocity(Vector2 velocity) {
            
            if (_velocity.x == 0 && _velocity.y == 0) {
                Vector2 randomVelocity = { (float)GetRandomValue((float)0, (float)5), (float)GetRandomValue((float)0, (float)5) };
                _velocity = randomVelocity;
            }

        }

    private:
        Vector2 _position;
        float _radius;
        float _density;
        Vector2 _velocity;
        float _mass;
        bool _enabled;
};