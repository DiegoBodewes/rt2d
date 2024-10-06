// platform.h

#ifndef PLATFORM_H
#define PLATFORM_H

#include <rt2d/entity.h>

class Platform: public Entity
{
public:
	Platform();
	virtual ~Platform();
	virtual void update(float deltaTime);
	//static std::vector<Platform*> allPlatforms;

private:
	/* Add your private declarations */
};

#endif /* PLATFORM_H */
