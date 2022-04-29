#include "content/contentmanager.h"
#include "content/contenttypereadermanager.h"
#include "graphics/effect.h"
#include "graphics/model.h"
#include "graphics/spritefont.h"
#include "graphics/texture2d.h"
#include "type.h"

#include <algorithm>
#include <memory>

using namespace yna::framework;
using namespace yna::framework::content;

static ContentTypeReaderManager _ContentTypeReaderManager;

ContentManager::ContentManager(IServiceProvider* serviceProvider)
    : _serviceProvider(serviceProvider),
      RootDirectory(_rootDirectory), ServiceProvider(_serviceProvider)
{ }

ContentManager::ContentManager(IServiceProvider* serviceProvider, const std::string& rootFirectory)
    : _serviceProvider(serviceProvider), _rootDirectory(rootFirectory),
      RootDirectory(_rootDirectory), ServiceProvider(_serviceProvider)
{ }

graphics::Effect* ContentManager::LoadEffect(const std::string& assetName) { return nullptr; }

graphics::Model* ContentManager::LoadModel(const std::string& assetName) { return nullptr; }

graphics::SpriteFont* ContentManager::LoadSpriteFont(const std::string& assetName) { return nullptr; }

graphics::Texture2D* ContentManager::LoadTexture2D(const std::string& assetName)
{
    auto result = static_cast<graphics::Texture2D*>(Load(assetName));

    if (result != nullptr)
    {
        return result;
    }

    auto reader = _ContentTypeReaderManager.GetTypeReader(Type(typeid(graphics::Texture2D).name()));
    if (reader == nullptr)
    {
        return nullptr;
    }

    std::unique_ptr<Stream, std::function<void(Stream*)>> stream(OpenStream(assetName), [] (Stream* ptr) { ptr->Close(); delete ptr; });
    if (stream == nullptr)
    {
        return nullptr;
    }

    ContentReader contentReader(stream.get(), this);

    result = static_cast<graphics::Texture2D*>(reader->Read(&contentReader));

    return result;
}

void* ContentManager::Load(const std::string& assetName)
{
    auto key = assetName;

    std::replace(key.begin(), key.end(), '\\', '/');

    auto found = _loadedAssets.find(key);

    if (found != _loadedAssets.end())
    {
        return found->second;
    }

    return nullptr;
}

class ReadFileStream : public Stream
{
    FILE* _file;
    long _length;
public:
    ReadFileStream(const std::string& filename)
        : _file(0), _length(0)
    {
        _file = fopen(filename.c_str(), "r");
        fseek(_file, 0, SEEK_END);
        _length = ftell(_file);
        fseek(_file, 0, SEEK_SET);
    }

    virtual bool CanRead() { return _file != nullptr; }
    virtual bool CanSeek() { return _file != nullptr; }
    virtual bool CanWrite() { return false; }
    virtual long Length() { return _length; }
    virtual long Position() { return _file != nullptr ? ftell(_file) : 0; }

    // When overridden in a derived class, sets the position within the current stream.
    virtual void Seek(long offset, SeekOrigin origin)
    {
        fseek(_file, offset, origin == SeekOrigin::Begin ? SEEK_SET : origin == SeekOrigin::Current ? SEEK_CUR : SEEK_END);
    }

    // When overridden in a derived class, reads a sequence of bytes from the current stream
    //      and advances the position within the stream by the number of bytes read.
    virtual long Read(std::vector<byte>& buffer, long offset, long count)
    {
        if (offset != 0)
        {
            Seek(offset, SeekOrigin::Current);
        }

        std::vector<unsigned char> buf(count);
        auto readBytes = fread(reinterpret_cast<byte*>(buf.data()), sizeof(byte), count, _file);

        buffer.swap(buf);

        return readBytes;
    }

    // When overridden in a derived class, writes a sequence of bytes to the current stream
    //      and advances the current position within this stream by the number of bytes written.
    virtual void Write(const std::vector<byte>& buffer, long offset, long count) { }

    // Closes the current stream and releases any resources (such as sockets and file handles)
    //      associated with the current stream.
    virtual void Close()
    {
        fclose(_file);
        _file = nullptr;
    }
};

Stream* ContentManager::OpenStream(const std::string &assetName)
{
    auto result = new ReadFileStream(assetName);

    if (result->CanRead())
    {
        return result;
    }

    return nullptr;
}

void ContentManager::Unload()
{ }

//bool ContentManager::ReadAsset(const std::string& assetName, std::vector<unsigned char>& buffer)
//{
//    // todo: determine full filename
//    std::string filename = assetName;

//    buffer.clear();

//    auto file = fopen(filename.c_str(), "r");
//    if (file != nullptr)
//    {
//        fseek(file, 0, SEEK_END);
//        auto size = ftell(file);
//        fseek(file, 0, SEEK_SET);

//        std::vector<unsigned char> buf(size);
//        fread(reinterpret_cast<unsigned char *>(buf.data()), sizeof(unsigned char), size + 1, file);

//        fclose(file);
//        buffer.swap(buf);

//        return true;
//    }

//    return false;
//}
