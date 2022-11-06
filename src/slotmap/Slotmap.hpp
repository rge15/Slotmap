#pragma once
#include <slotmap/using/typeAlias.hpp>

struct IdPair
{
	Size_t _id{ 0 };
	int _gen {-1};
};

template<typename T>
class Slotmap
{		
	using Indices = Vector<IdPair>;
	using Data = Vector< T >;

	private:
		int _genCtr { 0 };
		Size_t _free { 0 };

		Indices _index {};

		Data _data {};

		Vector<Size_t> _clear {};

		void
		moveDataSlot() noexcept;

		void
		resize() noexcept;

		Size_t
		getDataId( const T& p_data ) const noexcept;

		Size_t
		getIndexPair( const T& p_val ) noexcept;

		void
		checkSize() noexcept;

		void
		renumIndexChain() noexcept;

	public:
		Slotmap( Size_t p_size = 10 ) noexcept;

		~Slotmap() = default;

		IdPair
		addSlot( T&& p_data ) noexcept;

		IdPair
		addSlot( T& p_data ) noexcept;

		void
		deleteSlot( const IdPair& p_slot ) noexcept;

};

#include "Slotmap.tpp"