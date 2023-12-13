<?php 

class Node{

    protected int $value;
    
    protected Node|null $pos = null;

    protected Node|null $prev = null;

    public function __construct(int $value)
    {
        
        $this->value = $value;

    }

    public function getValue(){

        return $this->value;

    }

    public function setPos(Node $node){

        $this->pos = $node;

    }

    public function setPrev(Node $node){

        $this->prev = $node;

    }

    public function getPos(){

        return $this->pos;

    }

    public function getPrev(){

        return $this->prev;

    }

}

?>