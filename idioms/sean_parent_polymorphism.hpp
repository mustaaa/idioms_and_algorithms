#ifndef SEAN_PAREN_POLYMORPHISM_H
#define SEAN_PAREN_POLYMORPHISM_H

#include <utility>
#include <iostream>
#include <memory>

class object_t // this is the type which is contained in the container
{
public:
    template <typename T> //T models Drawable
    object_t(T x) : self_(std::make_shared<model<T>>(std::move(x)))
    {

    }
    void draw(std::ostream &out, std::size_t position) const //interface function, calls the model<T>::draw_ function
    {
        self_->draw_(out, position);
    }
    std::string get_typename() const
    {
        return self_->get_typename();
    }

private:
    struct concept_t
    {
        virtual ~concept_t() = default;
        virtual void draw_(std::ostream&, std::size_t) const = 0;
        virtual std::string get_typename () const {return std::string();}
    };

    template <typename T>
    struct model : concept_t
    {
        model(T x) : data_(std::move(x)) {} //model<T> constructor
        void draw_(std::ostream &out, std::size_t position) const //override draw_ function of the concept_t,
        {
            data_.draw(out, position);
        }
        virtual std::string get_typename() const
        {
            return data_.get_typename();
        }
        T data_;
    };

    std::shared_ptr<const concept_t> self_;
};

void sean_parent_polymorphism();

#endif // SEAN_PAREN_POLYMORPHISM_H
