#pragma once

class Speed : public Module {
public:
	Speed() : Module::Module("Speed", "Fancy PI Speed", "yeemi#0", Keyboard::O) {};

	float speed = 2;

	float degreesToRadians(float degrees) {
		return degrees * (PI / 180.0f);
	}

	float radiansToDegrees(float radians) {
		return radians * (180.0f / PI);
	}

	void OnTick(physent* player) override {
        Vector3<float> cameraVector = player->camera;

        float yaw = cameraVector.x;

        yaw = degreesToRadians(yaw);

        Vector3<float> cameraDirection;
        cameraDirection.x = cos(yaw);
        cameraDirection.z = sin(yaw);

        float length = sqrt(cameraDirection.x * cameraDirection.x + cameraDirection.z * cameraDirection.z);
        if (length != 0.0f) {
            cameraDirection.x /= length;
            cameraDirection.z /= length;
        }

        Vector3<float> velocity(0.0f, 0.0f, 0.0f);

        if (player->strafe == -1) {
            velocity.x += speed * cameraDirection.x;
            velocity.z += speed * cameraDirection.z;
        }
        else if (player->strafe == 1) {
            velocity.x -= speed * cameraDirection.x;
            velocity.z -= speed * cameraDirection.z;
        }

        if (player->move == -1) {
            velocity.x -= speed * cameraDirection.z;
            velocity.z += speed * cameraDirection.x;
        }
        else if (player->move == 1) {
            velocity.x += speed * cameraDirection.z;
            velocity.z -= speed * cameraDirection.x;
        }

        player->vel.x = velocity.x;
        player->vel.y = velocity.z;
	};
};