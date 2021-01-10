#include "Deletecomp.h"
#include "..\ApplicationManager.h"
#include "../Components/Gate.h"
#include "../Components/LED.h"
#include "../Components/switch_key.h"
Deletecomp::Deletecomp(ApplicationManager* pApp) :Action(pApp)
{

}
void Deletecomp::ReadActionParameters()
{

}

void Deletecomp::Execute()
{
	for (int i = 0; i < pManager->get_compcount(); i++)
	{
		Component* comp = pManager->Check(i);
		if (comp != NULL)
		{
			Gate* gate = dynamic_cast<Gate*>(comp);
			switch_key* key = dynamic_cast<switch_key*>(comp);
			LED* led = dynamic_cast<LED*>(comp);
			Connection* conn = dynamic_cast<Connection*>(comp);
			if (gate != NULL)
			{
				OutputPin* outputpin_gate = gate->getoutputpin();
				for (int j = 0; j < pManager->get_compcount(); j++)
				{
					Connection* connected_conn = pManager->Check_conn(j);
					if (connected_conn != NULL)
					{
						OutputPin* source_conn = connected_conn->getSourcePin();
						if (outputpin_gate == source_conn)
						{
							connected_conn->set_selected(true);
						}
						InputPin* Dest_conn = connected_conn->getDestPin();
						for (int k = 0; k < gate->no_inputs(); k++)
						{
							if (Dest_conn == gate->getinputpin(k))
							{
								connected_conn->set_selected(true);
							}
						}
					}
				}
			}
			else if (key != NULL)
			{
				OutputPin* outputpin_key = key->getoutputpin();
				for (int j = 0; j < pManager->get_compcount(); j++)
				{
					Connection* connected_conn = pManager->Check_conn(j);
					if (connected_conn != NULL)
					{
						OutputPin* source_conn = connected_conn->getSourcePin();
						if (outputpin_key == source_conn)
						{
							connected_conn->set_selected(true);
						}
					}
				}
			}
			else if (led != NULL)
			{
				for (int j = 0; j < pManager->get_compcount(); j++)
				{
					Connection* connected_conn = pManager->Check_conn(j);
					if (connected_conn != NULL)
					{
						InputPin* Dest_conn = connected_conn->getDestPin();
						if (Dest_conn == led->getinputpin())
						{
							connected_conn->set_selected(true);
						}
					}
				}
			}
			else if (conn != NULL)
			{
				///seting the destination pin
				InputPin* Destpin_conn = conn->getDestPin();
				Component* comp_dest = Destpin_conn->getComponent();
				Gate* gate_ptr = dynamic_cast<Gate*>(comp_dest);
				LED* led_ptr = dynamic_cast<LED*>(comp_dest);
				if (gate_ptr != NULL)
				{
					for (int j = 0; j < gate_ptr->no_inputs(); j++)
					{
						if (Destpin_conn == gate_ptr->getinputpin(j))
						{
							gate_ptr->set_connection(false, j);
						}
					}
				}
				else if (led_ptr != NULL)
				{
					led_ptr->set_connection(false);
				}
				///seting the source pin
				OutputPin* Sourcepin_conn = conn->getSourcePin();
				Connection** conn_source_ptr = Sourcepin_conn->get_m_Connections();
				int* num_conn_ptr = &(Sourcepin_conn->get_m_Conn());
				int num_conn = *num_conn_ptr;
				for (int j = 0; j < num_conn; j++)
				{
					if (conn_source_ptr[j] == conn)
					{
						Connection* p = conn_source_ptr[j];
						conn_source_ptr[j] = conn_source_ptr[num_conn - 1];
						conn_source_ptr[num_conn - 1] = p;
						conn_source_ptr[num_conn - 1] = NULL;
						num_conn--;
						j--;
						*num_conn_ptr = num_conn;
					}

				}
			}

		}

	}
	for (int i = 0; i < pManager->get_compcount(); i++)
	{
		Component* comp = pManager->Check(i);
		if (comp != NULL)
		{
			pManager->Delete(i);
			i--;
		}
	}
}
void Deletecomp::Undo()
{
}

void Deletecomp::Redo()
{
}
Deletecomp::~Deletecomp(void)
{
}