#pragma once

namespace math {
    //  Specify inclusivity for Contains method
    struct RangeContainsParams {
        bool left = false, right = false;
    };
    
    //  Specify params for min and max for Overlaps method
    struct RangeOverlapParams {
        RangeContainsParams left = {}, right = {};
    };
    
    template<typename T>
    class Range {
    private:
        T m_Min, m_Max;
        
    public:
        //  Constructors
        Range(const T& min, const T& max)
            : m_Min(min), m_Max(max) {
            if (min > max) printf("Range min must be less than max.");
        }
        Range(const Range<T>& other) { operator = (other); }
        Range(Range<T>&& other) { operator = (other); }
        
        //  Override == operator
        bool operator == (const Range<T>& other) const {
            //  Test if min and max are within EPSILON of eachother
            return isZero(m_Min - other.m_Min) && isZero(m_Max - other.m_Max);
        }
        
        //  Override != operator
        bool operator != (const Range<T>& other) const {
            return !isZero(m_Min - other.m_Min) || !isZero(m_Max - other.m_Max);
        }
        
        //  Override + operator
        Range<T> operator + (const T& t) const {
            return Range<T>(m_Min + t, m_Max + t);
        }
        
        /*
         Test if t is within min and max
         Contains(t)                     non inclusive
         Contains(t, {true,  false})     min inclusive
         Contains(t, {false, true })     max inclusive
         Contains(t, {true,  true })     all inclusive
         */
        bool Contains(const T& t, const RangeContainsParams& params = {}) const {
            //  If left inclusive, use min <= t, else use min < t
            //  If right inclusive, use t <= max, else use t < max
            return (params.left ? m_Min <= t : m_Min < t) && (params.right ? t <= m_Max : t < m_Max);
        }
        
        /*                                                    /---------------+---------------\
         Test if other contains values within this range's    |   other.min   |   other.max   |
         min and max values                                   |---------------|---------------|
         Overlaps(other)                                      | non inclusive | non inclusive |
         Overlaps(other, {{false, false}, {false, true }})    | non inclusive | max inclusive |
         Overlaps(other, {{false, false}, {true,  false}})    | non inclusive | min inclusive |
         Overlaps(other, {{false, false}, {true,  true }})    | non inclusive | all inclusive |
         Overlaps(other, {{false, true},  {false, false })    | max inclusive | non inclusive |
         Overlaps(other, {{false, true},  {false, true }})    | max inclusive | max inclusive |
         Overlaps(other, {{false, true},  {true,  false}})    | max inclusive | min inclusive |
         Overlaps(other, {{false, true},  {true,  true }})    | max inclusive | all inclusive |
         Overlaps(other, {{true,  false}, {false, false}})    | min inclusive | non inclusive |
         Overlaps(other, {{true,  false}, {false, true }})    | min inclusive | max inclusive |
         Overlaps(other, {{true,  false}, {true,  false}})    | min inclusive | min inclusive |
         Overlaps(other, {{true,  false}, {true,  true }})    | min inclusive | all inclusive |
         Overlaps(other, {{true,  true},  {false, false })    | all inclusive | non inclusive |
         Overlaps(other, {{true,  true},  {false, true }})    | all inclusive | max inclusive |
         Overlaps(other, {{true,  true},  {true,  false}})    | all inclusive | min inclusive |
         Overlaps(other, {{true,  true},  {true,  true }})    | all inclusive | all inclusive |
         *///                                                 \---------------+---------------/
        bool Overlaps(const Range<T>& other, const RangeOverlapParams& params = {}) const {
            //  If other.min is within min and max OR
            //  If other.max is within min and max
            return Contains(other.m_Min, params.left) || Contains(other.m_Max, params.right);
        }
        
        //  Get minimum of range
        const T& GetMin() const { return m_Min; }
        
        //  Get maximum of range
        const T& GetMax() const { return m_Max; }
        
        //  Clamp t between min and max of range
        T Clamp(const T& t) { return clamp(t, m_Min, m_Max); }
        
        //  Distance covered by the range
        T GetSpan() const { return m_Max - m_Min; }
    };
}

