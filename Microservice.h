
#ifndef C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_MICROSERVICE_H_
#define C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_MICROSERVICE_H_


class Microservice
{


public:


  /*! Configuração do microsserviço */
  Microservice ()
  {

    /*! Configura as entradas */
    enable        = 1;

    /*! Configura as saídas */
    partialResult = 0;
    result        = 0;

    /*! Ajusta a saída de sinalização */
    enableActive = 1;
    setActive ();

  }


  /*! --------------------------------------------------------------------------
   * @brief      Ajusta a entrada de habilita do microsserviço.
   *
   * @param[in]  enable   -  0..1, Valor de habilita/desabilita a operação
   *                               da lógica.
   * ---------------------------------------------------------------------------
   */
  void setEnable (int enable)
  {

    /*! Ajusta a entrada enable */
    if ((enable >= 0) && (enable <= 1))
    {
      Microservice::enable = enable;

      /*! Ajusta a saída de sinalização */
      enableActive = 1;
    }
    else
    {
      /*! Ajusta a saída de sinalização */
      enableActive = 0;
    }
    setActive ();

  }
  /*! --------------------------------------------------------------------------
   *  @brief      Executa o microsserviço caso este esteja habilitado.
   *  --------------------------------------------------------------------------
   */
  virtual void doMicroservice () = 0;


  /*! --------------------------------------------------------------------------
   *  @brief      Executa o reset caso o microsserviço esteja habilitado.
   *  --------------------------------------------------------------------------
   */
  virtual void doResetMicroservice () = 0;


  /*! --------------------------------------------------------------------------
   *  @brief      Adquire o valor da saída parcial do microsserviço.
   *
   *  @return     Valor do resultado parcial.
   *  --------------------------------------------------------------------------
   */
  unsigned int getPartialResult ()
  {
    return partialResult;
  }


  /*! --------------------------------------------------------------------------
   *  @brief      Adquire o valor da saída final do microsserviço.
   *
   *  @return     Valor do resultado final.
   *  --------------------------------------------------------------------------
   */
  unsigned int getResult ()
  {
    return result;
  }


  /*! --------------------------------------------------------------------------
   *  @brief      Adquire o valor da saída de sinalização.
   *
   *  @return     Valor da saída de sinalização.
   * ---------------------------------------------------------------------------
   */

protected:


  void setActive ()
  {
    active = enableActive;
  }

  /*! Entrada do microsserviço */
  int             enable;

  /*! Controle de sinalização do microsserviço */
  int             enableActive;

  /*! Saídas do microsserviço */
  unsigned int    partialResult;
  unsigned int    result;
  
  int             active;

};

#endif // C__USERS_MIGUELGRIMM_DESKTOP_CPPLINT_MASTER_MICROSERVICE_H_
