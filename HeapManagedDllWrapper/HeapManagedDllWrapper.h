// HeapManagedDllWrapper.h

#pragma once

#include "HeapModificable.h"

using namespace System;

namespace HeapManagedDllWrapper {

	public ref class HeapModificableWrapper
	{
	public:

		ref class IteradorWrapper
		{
		public:
			IteradorWrapper();
			IteradorWrapper(IteradorWrapper% it);
			IteradorWrapper(HeapModificable::Iterador iter);
			bool haySiguienteWrapper();
			int SiguienteWrapper();
			void eliminarSiguienteWrapper();

			HeapModificable::Iterador *iterWrapper;

		private:
			//HeapModificable::Iterador *iterWrapper;
		};

		HeapModificableWrapper();
		IteradorWrapper^ encolarWrapper(int a);
		void encolarWrapper(int a, IteradorWrapper^ iterW);
		bool esVaciaWrapper();
		int proximoWrapper();
		void desencolarWrapper();

	private:
		HeapModificable *heapCppClass;
	};
}
