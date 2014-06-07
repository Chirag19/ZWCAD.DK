#ifndef _ZCRXAUTORESET_H
#define _ZCRXAUTORESET_H


template<class T>
class ZcRxAutoReset
{
public:
	ZcRxAutoReset(T& data, const T& newval) 
		: m_data(data)
		, m_oldval(data)
	{
		m_data = newval;
	}

	virtual ~ZcRxAutoReset()
	{
		m_data = m_oldval;
	}

private:
	T&			m_data;
	const T&	m_oldval;
};


class ZcRxAutoBitset
{
public:
	ZcRxAutoBitset(int& flag, int bits) 
		: m_flag(flag)
		, m_bits(bits)
	{
		m_flag |= bits;
	}

	virtual ~ZcRxAutoBitset()
	{
		m_flag &= ~m_bits;
	}

private:
	int& m_flag;
	int m_bits;
};

#endif

