#include "contentreader.h"

using namespace yna::framework::content;

ContentReader::ContentReader(Stream* stream, class ContentManager* contentManager)
    : _stream(stream), _contentManager(contentManager), ContentManager(_contentManager), BaseStream(_stream)
{ }

bool ContentReader::ReadBytes(int count, std::vector<byte>& buffer)
{
    return _stream->Read(buffer, 0, count) == count;
}

//bool ContentReader::ReadBytes(int count, std::vector<unsigned char>& buffer)
//{
//    // todo: determine full filename
//    std::string filename;

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
