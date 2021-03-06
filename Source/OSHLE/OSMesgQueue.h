#ifndef OSHLE_OSMESGQUEUE_H_
#define OSHLE_OSMESGQUEUE_H_

#include "ultra_os.h"

#include "Core/Memory.h"

#include <stddef.h>		// ofsetof


class COSMesgQueue
{
public:

	inline COSMesgQueue(u32 addr)
	{
		p_base = (u8 *)ReadAddress(addr);
	}

	// OSThread
	inline u32 GetEmptyQueue()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, mtqueue));
	}

	inline u32 GetFullQueue()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, fullqueue));
	}

	inline s32 GetValidCount()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, validCount));
	}

	inline s32 GetFirst()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, first));
	}

	inline s32 GetMsgCount()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, msgCount));
	}

	inline u32 GetMesgArray()
	{
		return QuickRead32Bits(p_base, offsetof(OSMesgQueue, msg));
	}

	inline void SetEmptyQueue(u32 queue)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, mtqueue), queue);
	}

	inline void SetFullQueue(u32 queue)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, fullqueue), queue);
	}

	inline void SetValidCount(s32 nCount)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, validCount), nCount);
	}

	inline void SetFirst(s32 nFirst)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, first), nFirst);
	}

	inline void SetMsgCount(s32 nMsgCount)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, msgCount), nMsgCount);
	}

	inline void SetMesgArray(u32 dwMsgBuffer)
	{
		QuickWrite32Bits(p_base, offsetof(OSMesgQueue, msg), dwMsgBuffer);
	}


protected:
	u8* p_base;

};

#endif // OSHLE_OSMESGQUEUE_H_
