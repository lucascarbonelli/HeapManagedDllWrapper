// Archivo DLL principal.

#include "stdafx.h"
#include "HeapManagedDllWrapper.h"

HeapManagedDllWrapper::HeapModificableWrapper::HeapModificableWrapper()
{
	heapCppClass = new HeapModificable();
}

HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper^ HeapManagedDllWrapper::HeapModificableWrapper::encolarWrapper(int a)
{
	HeapModificable::Iterador it = heapCppClass->encolar(a);
	IteradorWrapper itw = IteradorWrapper(it);
	IteradorWrapper^ itwp = gcnew IteradorWrapper(itw);
	return itwp;
	//return gcnew IteradorWrapper(heapCppClass->encolar(a));
}

void HeapManagedDllWrapper::HeapModificableWrapper::encolarWrapper(int a, IteradorWrapper^ iterW)
{
	iterW->iterWrapper = &heapCppClass->encolar(a);
}

bool HeapManagedDllWrapper::HeapModificableWrapper::esVaciaWrapper()
{
	return heapCppClass->esVacia();
}

int HeapManagedDllWrapper::HeapModificableWrapper::proximoWrapper()
{
	return heapCppClass->proximo();
}

void HeapManagedDllWrapper::HeapModificableWrapper::desencolarWrapper()
{
	return heapCppClass->desencolar();
}

HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::IteradorWrapper()
{
	iterWrapper = nullptr;
}

HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::IteradorWrapper(IteradorWrapper % it)
{
	iterWrapper = it.iterWrapper;
	//throw gcnew System::NotImplementedException();
}

HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::IteradorWrapper(HeapModificable::Iterador iter)
{
	iterWrapper = &iter;
}

bool HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::haySiguienteWrapper()
{
	return iterWrapper->haySiguiente();
}

int HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::SiguienteWrapper()
{
	return iterWrapper->Siguiente();
}

void HeapManagedDllWrapper::HeapModificableWrapper::IteradorWrapper::eliminarSiguienteWrapper()
{
	iterWrapper->eliminarSiguiente();
}