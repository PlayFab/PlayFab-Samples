//--------------------------------------------------------------------------------------
// BatchRemovalCollection.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
//--------------------------------------------------------------------------------------

#pragma once

template<class T>
class BatchRemovalCollection
{
public:
    inline void QueuePendingRemoval(const typename std::vector<T>::value_type &item)
    {
        m_pendingRemovals.push_back(item);
    }

    void ApplyPendingRemovals()
    {
        m_activeObjects.insert(m_activeObjects.end(), m_pendingAdds.begin(), m_pendingAdds.end());
        m_pendingAdds.clear();

        for (size_t i = 0; i < m_pendingRemovals.size(); i++)
        {
            auto itr = std::find(std::begin(m_activeObjects), std::end(m_activeObjects), m_pendingRemovals[i]);
            m_activeObjects.erase(itr);
        }
        m_pendingRemovals.clear();
    }

    inline void clear()
    {
        m_pendingAdds.clear();
        m_pendingRemovals.clear();
        m_activeObjects.clear();
    }

    inline void push_back(const typename std::vector<T>::value_type &item)
    {
        m_pendingAdds.push_back(item);
    }

    inline typename std::vector<T>::iterator begin()
    {
        return m_activeObjects.begin();
    }

    inline typename std::vector<T>::const_iterator cbegin() const
    {
        return m_activeObjects.cbegin();
    }

    inline typename std::vector<T>::iterator end()
    {
        return m_activeObjects.end();
    }

    inline typename std::vector<T>::const_iterator cend() const
    {
        return m_activeObjects.cend();
    }

    inline typename std::vector<T>::size_type size() const
    {
        return m_activeObjects.size();
    }

    inline typename std::vector<T>::size_type total_size() const
    {
        return m_activeObjects.size() + m_pendingAdds.size();
    }

    inline typename std::vector<T>::reference operator[](typename std::vector<T>::size_type index)
    {
        return m_activeObjects[index];
    }

    inline typename std::vector<T>::const_reference operator[](typename std::vector<T>::size_type index) const
    {
        return m_activeObjects[index];
    }

    inline typename std::vector<T>::const_iterator erase(typename std::vector<T>::const_iterator itr)
    {
        return m_activeObjects.erase(itr);
    }

private:
    std::vector<T> m_pendingAdds;
    std::vector<T> m_pendingRemovals;
    std::vector<T> m_activeObjects;
};