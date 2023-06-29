#ifndef C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_BUILDER_H_
#define C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_BUILDER_H_

class Builder
{


public:


  /*! Configuração da fábrica */
  Builder ()
  {
    /*! Configura as entradas da fábrica */
    enable       = 0;

    /*! Configura o controle da fábrica */
    newActive    = 1;
    enableActive = 1;
    setupActive  = 1;
    setActive ();
  }


  /*! Entrada da fábrica */
  void setEnable (int enable)
  {
    if ((enable >= 0) && (enable <= 1))
    {
      /*! Ajusta a entrada de habilita */
      Builder::enable = enable;
         
      /*! Ajusta a saída de sinalização */
      enableActive = 1;
      setActive ();
    }
    else
    {
      /*! Ajusta a saída de sinalização */
      enableActive = 0;
      setActive ();
    }
  }

  /*! Saída da fábrica */
  int getActive ()
  {
    return active;
  }


protected:


  /*! Saída da fábrica */
  virtual void setActive ()
  {
    active = newActive & enableActive & setupActive;
  }

  /*! Entrada da fábrica */
  int    enable;

  /*! Controles da fábrica */
  int    enableActive;
  int    newActive;
  int    setupActive;

  /*! Saída da fábrica */
  int    active;

};


#endif // C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_BUILDER_H_
