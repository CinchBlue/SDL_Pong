#ifndef TEXTURE_POOL_H_
#define TEXTURE_POOL_H_

#include "Common.h"

class Texture_Pool
{
    public:
        Texture_Pool();
        virtual ~Texture_Pool();

        void load_texture(std::string path);
        void unload_texture(std::string name);
        void unload_all_texture();

        SDL_Texture* get_texture(std::string name);
    protected:
    private:

        std::vector<SDL_Texture*> texture_pool;
        std::vector<std::string> texture_names;
};




#endif /* TEXTURE_POOL_H_ */
