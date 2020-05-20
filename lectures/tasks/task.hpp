#ifndef __TASK_HPP
#define __TASK_HPP

#include "printable.hpp"
#include "named.hpp"

class Task :
  // поддръжка на име на задачата
  public Named, 
  // интерфейс за извеждане
  public Printable {
public:
    Task(char const* n) : Named(n) {}

    void print(std::ostream& os = std::cout) const;

    // време за изпълнение на задачата
    virtual unsigned getExecutionTime() const = 0;

    // прогрес по задачата
    virtual unsigned getProgress() const = 0;

    // работа по задачата
    // параметърът time указва колко време искаме да работим по задачата
    // като резултат се връща неизработените единици време
    virtual unsigned work(unsigned time = 1) = 0;
};

#endif