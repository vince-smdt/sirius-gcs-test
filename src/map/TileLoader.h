#ifndef TILELOADER_H
#define TILELOADER_H

#include "ITileLoader.h"

#include <memory>
#include <vector>

class ITile;
class ITileSource;

class TileLoader : public ITileLoader {
public:
    TileLoader(std::shared_ptr<ITileSource> source);
    virtual ~TileLoader() = default;

    virtual void beginLoad(int z, int xmin, int xmax, int ymin, int ymax) override;
    virtual ImTextureID tileAt(int z, int x, int y) override;
    virtual int tileCount() const override {
        return _tiles.size();
    }
    virtual void endLoad() override {
    }

private:
    std::shared_ptr<ITileSource> _source;
    std::vector<std::shared_ptr<ITile>> _tiles;
};

#endif // TILELOADER_H
