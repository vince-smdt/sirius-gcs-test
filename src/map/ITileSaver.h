#ifndef ITILESAVER_H
#define ITILESAVER_H

#include <memory>
#include <vector>

class ITile;
class ITileSaver {
public:
    virtual ~ITileSaver() = default;
    virtual bool save(std::shared_ptr<ITile> tile) const = 0;
    virtual bool saveMulti(const std::vector<std::shared_ptr<ITile>>& tiles) const = 0;
};

#endif // ITILESAVER_H
