#ifndef TimeLayer_h__
#define TimeLayer_h__

#include "BasicLayer.h"
class TimeLayer:public BasicLayer
{
public:
	TimeLayer();
	~TimeLayer();
	virtual bool init()override;
	void SetView();
	static Scene*scene();
	void time_counting_down(float t);
	CREATE_FUNC(TimeLayer);
private:
	int counter;
};
#endif // TimeLayer_h__
