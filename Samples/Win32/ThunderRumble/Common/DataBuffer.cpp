//--------------------------------------------------------------------------------------
// DataBuffer.cpp
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#include "pch.h"
#include "DataBuffer.h"

using namespace ThunderRumble;

DataBufferReader::DataBufferReader(const std::vector<uint8_t> &buffer) :
    m_pos(0),
    m_buffer(buffer)
{
}

uint8_t DataBufferReader::ReadByte()
{
    uint8_t data;

    ReadData(&data, sizeof(data));

    return data;
}

int32_t DataBufferReader::ReadInt32()
{
    int32_t data;

    ReadData(&data, sizeof(data));

    return data;
}

uint32_t DataBufferReader::ReadUInt32()
{
    uint32_t data;

    ReadData(&data, sizeof(data));

    return data;
}

float DataBufferReader::ReadSingle()
{
    float data;

    ReadData(&data, sizeof(data));

    return data;
}

double DataBufferReader::ReadDouble()
{
    double data;

    ReadData(&data, sizeof(data));

    return data;
}

std::wstring DataBufferReader::ReadString()
{
    size_t length;
    ReadData(&length, sizeof(length));

    auto start = reinterpret_cast<const wchar_t*>(m_buffer.data() + m_pos);
    auto end = start + (length / sizeof(wchar_t));

    m_pos += length;

    return std::wstring(start, end);
}

void DataBufferReader::ReadData(void *dest, size_t length)
{
    if (m_pos + length > m_buffer.size())
    {
        // Read past the end of the buffer
        throw std::runtime_error("Attempted to read beyond the length of the buffer");
    }
    memcpy(dest, m_buffer.data() + m_pos, length);
    m_pos += length;
}

DataBufferWriter::DataBufferWriter(size_t bufferSize) :
    m_pos(0),
    m_buffer(bufferSize)
{

}

void DataBufferWriter::WriteByte(uint8_t data)
{
    WriteData(&data, sizeof(data));
}

void DataBufferWriter::WriteInt32(int32_t data)
{
    WriteData(&data, sizeof(data));
}

void DataBufferWriter::WriteUInt32(uint32_t data)
{
    WriteData(&data, sizeof(data));
}

void DataBufferWriter::WriteSingle(float data)
{
    WriteData(&data, sizeof(data));
}

void DataBufferWriter::WriteDouble(double data)
{
    WriteData(&data, sizeof(data));
}

void DataBufferWriter::WriteString(const std::wstring &data)
{
    size_t length = data.length() * sizeof(wchar_t);
    WriteData(&length, sizeof(size_t));
    WriteData(data.c_str(), length);
}

std::vector<uint8_t>&& ThunderRumble::DataBufferWriter::GetBuffer()
{
    // Shrink the buffer to the used contents
    m_buffer.resize(m_pos);

    return std::move(m_buffer);
}

void DataBufferWriter::WriteData(const void *data, size_t length)
{
    if (m_pos + length > m_buffer.size())
    {
        m_buffer.resize(m_buffer.size() + 512);
    }
    memcpy(m_buffer.data() + m_pos, data, length);
    m_pos += length;
}
