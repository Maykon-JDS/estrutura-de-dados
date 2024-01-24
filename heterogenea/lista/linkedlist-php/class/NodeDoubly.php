<?php 

namespace Lista\class;

use Lista\class\Node;

class NodeDoubly extends Node{

    protected NodeDoubly|null $prev;

    public function __construct(mixed $value, Node|null $next = null, NodeDoubly|null $prev = null)
    {
        
        $this->value = $value;

        $this->next = $next;

        $this->prev = $prev;

    }

    public function getPrev() : NodeDoubly|null
    {

        return $this->prev;

    }

    public function setPrev(NodeDoubly|null $prev) : void
    {

        $this->prev = $prev;

    }

}

?>