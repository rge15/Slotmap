
template<typename T>
Slotmap<T>::Slotmap( Size_t p_size ) noexcept
: _capacity{ p_size }
{
	_data.reserve(_capacity);
	_clear.reserve(_capacity);

	_index.resize(_capacity);

	int i = 0;
	for(auto& pair : _index)
		pair._id = ++i;

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
void
Slotmap<T>::resize( Size_t p_nexCapacity ) noexcept
{
	_clear.reserve( p_nexCapacity );

	_index.resize( p_nexCapacity );

	int i = _free;
	for(auto& pair : _index)
		if(pair._gen == -1)
			pair._id = ++i;

}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
Size_t
Slotmap<T>::getDataId( const T& p_data ) const noexcept
{
	Size_t ctr { 0 };

	for(auto& value : _data)
	{
		if( &value == &p_data)
			return ctr;
		++ctr;
	}

	return -1;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
void
Slotmap<T>::checkSize() noexcept
{
	auto dataCapacity = _data.capacity();

	if( dataCapacity != _capacity )
		resize( dataCapacity );
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
IdPair
Slotmap<T>::addSlot(T& p_data) noexcept
{
	auto& val = _data.emplace_back( std::move(p_data) );

	checkSize();

	_clear.emplace_back( _free );

	Size_t keyUser = getIndexPair( val );

	return { keyUser , _genCtr++ };
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
IdPair
Slotmap<T>::addSlot(T&& p_data) noexcept
{
	auto& val = _data.emplace_back( p_data );

	checkSize();

	_clear.emplace_back( _free );

	Size_t keyUser = getIndexPair( val );

	return { keyUser , _genCtr++ };
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
Size_t
Slotmap<T>::getIndexPair( const T& p_val ) noexcept
{
	auto& idPair = _index[_free];
	Size_t userKey = _free;
	_free = idPair._id;
	idPair._gen = _genCtr;
	idPair._id = getDataId( p_val );

	return userKey;
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------

template<typename T>
void
Slotmap<T>::deleteSlot( const IdPair& p_pair ) noexcept
{
	//TODO : Hacer la lógica de borrado
	//1º : Checkear que el indice sea valido
	//2º : Guardamos el _index[p_pair._id]._id en dataToErase
	//3º : Pasar el p_pair._id a _free y el _free al _index[p_pair._id]._id
	//4º : Pasar el _index[p_pair._id]._gen a -1
	//5º : Pasamos el último de _data y el último de _clear a _data[dataToErase] y _clear[dataToErase]
	//6º : Una vez pasado los datos, con el _clear[dataToErase] cambiamos el _indices[_clear[dataToErase]] a dataToErase
	//7º : Check que funciona y eres el puto amo ::sunglasses_emoji::
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


template<typename T>
void
Slotmap<T>::moveDataSlot() noexcept
{

}
