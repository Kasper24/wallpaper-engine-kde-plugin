#pragma once

#include "Type.h"
#include "Resource.h"
#include "Interface/IGraphicManager.h"

#include <cstdint>
#include <string>
#include <functional>

namespace wallpaper {
namespace fg {

struct TextureResource : public Resource {
	struct Desc {
		uint16_t width {1};
		uint16_t height {1};
		std::string path;
		TextureFormat format {TextureFormat::RGBA8};
		TextureSample sample;
		std::function<std::shared_ptr<Image>(void)> getImgOp;

		std::string name;
	};

	void Initialize() {
		inited = true;
	}; 
	bool Initialed() const { return inited; };
	bool inited {false};

	HwTexHandle handle;
	Desc desc;
};


}
}
