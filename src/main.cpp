#include <slotmap/Slotmap.hpp>
// #include <iostream>

struct Pos
{
	float x { 0 }, y { 1 }, z { 2 };
	inline static int ctr { 0 };
	int pos { ctr++ };
};


int main()
{
	Slotmap<Pos> slot;
	auto& dataVec = slot.getDataVector();
	auto& clearVec = slot.getClearVector();
	auto& indexVec = slot.getIndexVector();

	std::cout << "#################### INIT ####################" << '\n';
	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	IdPair p0 = slot.addSlot({ 0., 0., 0. });
	IdPair p1 = slot.addSlot({ 1., 1., 1. });
	IdPair p2 = slot.addSlot({ 2., 2., 2. });
	IdPair p3 = slot.addSlot({ 3., 3., 3. });
	IdPair p4 = slot.addSlot({ 4., 4., 4. });
	IdPair p5 = slot.addSlot({ 5., 5., 5. });
	IdPair p6 = slot.addSlot({ 6., 6., 6. });


	std::cout << "#################### FIRST ITERATION ####################" << '\n';

	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	for(int i = 0; i < dataVec.size(); i++)
	{
		std::cout << "Position number : " << i << " Key Index " << indexVec[i]._id << " Gen value " << indexVec[i]._gen << " \\\\ " ;
		std::cout << "Generated number : " << dataVec[i].pos << " \\\\ ";
		std::cout << "X value : " << dataVec[i].x <<  " , Y value : " << dataVec[i].y <<  " , Z value : " << dataVec[i].z << " \\\\ ";
		std::cout << "Clear number : " << clearVec[i] << '\n';
	}


	std::cout << "#################### SECOND ITERATION ####################" << '\n';

	slot.deleteSlot(p2);
	slot.deleteSlot(p4);

	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	for(int i = 0; i < dataVec.size(); i++)
	{
		std::cout << "Position number : " << i << " Key Index " << indexVec[i]._id << " Gen value " << indexVec[i]._gen << " \\\\ " ;
		std::cout << "Generated number : " << dataVec[i].pos << " \\\\ ";
		std::cout << "X value : " << dataVec[i].x <<  " , Y value : " << dataVec[i].y <<  " , Z value : " << dataVec[i].z << " \\\\ ";
		std::cout << "Clear number : " << clearVec[i] << '\n';
	}

	std::cout << "#################### THIRD ITERATION ####################" << '\n';

	IdPair p7 = slot.addSlot({ 7., 7., 7. });
	IdPair p8 = slot.addSlot({ 8., 8., 8. });

	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	for(int i = 0; i < dataVec.size(); i++)
	{
		std::cout << "Position number : " << i << " Key Index " << indexVec[i]._id << " Gen value " << indexVec[i]._gen << " \\\\ " ;
		std::cout << "Generated number : " << dataVec[i].pos << " \\\\ ";
		std::cout << "X value : " << dataVec[i].x <<  " , Y value : " << dataVec[i].y <<  " , Z value : " << dataVec[i].z << " \\\\ ";
		std::cout << "Clear number : " << clearVec[i] << '\n';
	}

	std::cout << "#################### FOURTH ITERATION ####################" << '\n';

	IdPair p9 = slot.addSlot({ 9., 9., 9. });
	IdPair p10 = slot.addSlot({ 10., 10., 10. });
	IdPair p11 = slot.addSlot({ 11., 11., 11. });
	IdPair p12 = slot.addSlot({ 12., 12., 12. });

	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	for(int i = 0; i < dataVec.size(); i++)
	{
		std::cout << "Position number : " << i << " Key Index " << indexVec[i]._id << " Gen value " << indexVec[i]._gen << " \\\\ " ;
		std::cout << "Generated number : " << dataVec[i].pos << " \\\\ ";
		std::cout << "X value : " << dataVec[i].x <<  " , Y value : " << dataVec[i].y <<  " , Z value : " << dataVec[i].z << " \\\\ ";
		std::cout << "Clear number : " << clearVec[i] << '\n';
	}

	std::cout << "#################### FIFTH ITERATION ####################" << '\n';

	slot.deleteSlot(p1);
	slot.deleteSlot(p6);
	slot.deleteSlot(p10);
	slot.deleteSlot(p11);

// 1,6,10,2,4
	std::cout << "Size of vector : " << dataVec.size() << " Capacity of vector : " << dataVec.capacity() << '\n';

	for(int i = 0; i < dataVec.size(); i++)
	{
		std::cout << "Position number : " << i << " Key Index " << indexVec[i]._id << " Gen value " << indexVec[i]._gen << " \\\\ " ;
		std::cout << "Generated number : " << dataVec[i].pos << " \\\\ ";
		std::cout << "X value : " << dataVec[i].x <<  " , Y value : " << dataVec[i].y <<  " , Z value : " << dataVec[i].z << " \\\\ ";
		std::cout << "Clear number : " << clearVec[i] << '\n';
	}

	return 0;
}