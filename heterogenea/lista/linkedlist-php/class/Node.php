<?php 

namespace Lista\class;

class Node {
    
    protected mixed $value;

    protected Node|null $next;

    public function __construct(mixed $value, Node|null $next = null)
    {
        
        $this->value = $value;

        $this->next = $next;

    }

    public function getValue() : mixed
    {

        return $this->value;

    }

    public function setValue(mixed $value) : void
    {

        $this->value = $value;

    }

    public function getNext() : Node|null
    {

        return $this->next;

    }

    public function setNext(Node|null $next) : void
    {

        $this->next = $next;

    }

}



?>