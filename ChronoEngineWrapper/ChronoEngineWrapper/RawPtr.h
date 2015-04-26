#pragma once

namespace cew {

	template<typename T>
	public ref class RawPtr	{
	private:
		chrono::ChSharedPtr<T>* m_pPtr;

	public:
		RawPtr()
		{
			m_pPtr = NULL;
		}

		RawPtr(T* ptr)
		{
			m_pPtr = new  chrono::ChSharedPtr<T>(ptr);
		}

		RawPtr(const chrono::ChSharedPtr<T>& ptr)
		{
			m_pPtr = new  chrono::ChSharedPtr<T>(ptr);
		}

		template<class TT>
		RawPtr(const chrono::ChSharedPtr<TT>& ptr)
		{
			m_pPtr = new  chrono::ChSharedPtr<T>(ptr);
		}

		~RawPtr()
		{
			if(m_pPtr !=NULL)
			{
				delete m_pPtr;
				m_pPtr = NULL;
			}
		}

	

		property chrono::ChSharedPtr<T>* SharedPtr
		{
	
			chrono::ChSharedPtr<T>* get()
			{
				return m_pPtr;
			}
		}



		property T* Ptr
		{
			void set(T* value)
			{
				chrono::ChBody* ptrI = new chrono::ChBody();
				chrono::ChSharedPtr<chrono::ChBody>* ptr = new chrono::ChSharedPtr<chrono::ChBody>(ptrI);

				
				if(m_pPtr != nullptr)
				{
					delete m_pPtr;
				}
				
				m_pPtr = new chrono::ChSharedPtr<T>(value);
				
			}
			T* get()
			{
				return m_pPtr->get_ptr();
			}
		}

	};

}