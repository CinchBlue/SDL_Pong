#include "Texture_Pool.h"

Texture_Pool::Texture_Pool()
{
    //ctor
}

Texture_Pool::~Texture_Pool()
{
    //dtor
}

/*
Loads a PNG files, and stores it and its name in two vectors for
SDL_Texture* and std::string. While I could possibly eliminate strings
for efficiency, I've decided to use std::string for easier manipulation,
type safety, and easy translation to labels.
*/
void Texture_Pool::load_texture(std::string path)
{
    SDL_Texture* loaded_texture = NULL;
    SDL_Surface* loaded_surface = NULL;

    loaded_surface = IMG_Load(path.c_str());
    if (loaded_surface == NULL)
        std::cout << "File: " + path + " unable to be loaded!" << std::endl;
    else
    {
    	std::cout << "File: " + path + " loaded." << std::endl;
        loaded_texture = SDL_CreateTextureFromSurface(g_renderer, loaded_surface);
        if (loaded_texture == NULL)
        {
            std::cout << "File: " + path + " unable to be converted to SDL_Texture" << std::endl;
        }
        else
            std::cout << path << " loaded!" << std::endl;
    }

    SDL_FreeSurface(loaded_surface);

    texture_pool.push_back(loaded_texture);
    texture_names.push_back(path);
}

/*
Frees a texture, going by name. Refer to std::string.find()
*/
void Texture_Pool::unload_texture(std::string name)
{
    for (unsigned int i = 0; i < texture_names.size(); i++)
    {
        if (texture_names[i].find(name))
            SDL_DestroyTexture(texture_pool[i]);
            texture_names.erase(texture_names.begin() + (i));
            texture_pool.erase(texture_pool.begin() + (i));
    }
}

/*
Unloads all SDL_Texture.
*/
void Texture_Pool::unload_all_texture()
{
    for (unsigned int i = 0; i < texture_names.size(); i++)
    {
        SDL_DestroyTexture(texture_pool[i]);
        texture_names.erase(texture_names.begin() + (i));
        texture_pool.erase(texture_pool.begin() + (i));
    }
}

/*
Finds an SDL_Texture according to its file path, and returns
SDL_Texture*
*/
SDL_Texture* Texture_Pool::get_texture(std::string name)
{
    SDL_Texture* return_value_ptr = NULL;
    for (unsigned int i = 0; i < texture_names.size(); i++)
    {
        if (texture_names[i].find(name) != std::string::npos)
        {
            std::cout << "Pulling " << texture_names[i] << " from sprite pool." << std::endl;
            return_value_ptr = texture_pool[i];
        }
    }

    if (return_value_ptr == NULL)
        return NULL;
    else return return_value_ptr;
}

